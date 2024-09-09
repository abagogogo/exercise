import cv2
import sys

def match_features(desc1, desc2):
  bf = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck=True)
  matches = bf.match(desc1, desc2)
  return len(sorted(matches, key=lambda x:x.distance))

def load_video(video_path):
  cap = cv2.VideoCapture(video_path)
  frame_count = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
  print(f"{video_path} has {frame_count} frames")
  return cap, frame_count

def extract_orb_features(frame):
  orb = cv2.ORB_create()
  return orb.detectAndCompute(frame, None)

def process_video_frames(video_cap, frame_count):
  while video_cap.isOpened():
    ret, frame = video_cap.read()
    if not ret:
      print(f"Failed to read frame {frame_no}")
      continue


    frame_no = int(video_cap.get(cv2.CAP_PROP_POS_FRAMES))
    if frame_no == frame_count:
      break

    yield frame, frame_no

def match_frame_to_video(src_frame, dst_video):
  dst_cap, dst_frame_count  = load_video(dst_video) 
  src_keypoints, src_descriptors = extract_orb_features(src_frame)

  best_matches = 0
  best_frame = None
  best_frame_no = 0

  for dst_frame, dst_frame_no in process_video_frames(dst_cap, dst_frame_count):
    dst_keypoints, dst_descriptors = extract_orb_features(dst_frame)
    matches = match_features(src_descriptors, dst_descriptors)
    print(f'Matching to dst_video frame {dst_frame_no}, matches={matches}')

    if matches > best_matches:
      best_matches = matches
      best_frame = dst_frame
      best_frame_no = dst_frame_no

  print(f"Best matched frame = {best_frame_no}, matches = {best_matches}")
  dst_cap.release()
  return best_matches, best_frame

def match_videos(src_video, dst_video):
  src_cap, src_frame_count  = load_video(src_video) 

  for src_frame, src_frame_no in process_video_frames(src_cap, src_frame_count):
    print(f'Matching to {src_video} frame {src_frame_no} to {dst_video}')
    matches, matched_frame = match_frame_to_video(src_frame, dst_video)
    cv2.imshow('Source Frame', src_frame)
    cv2.imshow('Destination Frame', matched_frame)

    if cv2.waitKey(1000) == ord('q'):
      break

  src_cap.release()
  cv2.destroyAllWindows()

def main(argv=None):
  if argv is None:
      argv=sys.argv
  print('OpenCV version:', cv2.__version__)

  src_video = "IMG_0054.MOV"
  dst_video = "IMG_0290.MOV"
  match_videos(src_video, dst_video)

if __name__ == '__main__':
  sys.exit(main())
