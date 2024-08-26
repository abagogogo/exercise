import cv2
import sys


def match_features(desc1, desc2):
  bf = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck=True)
  matches = bf.match(desc1, desc2)
  matches = sorted(matches, key=lambda x:x.distance)
  return len(matches)

def video_load(video):
  cap = cv2.VideoCapture(video)
  frame_end = cap.get(cv2.CAP_PROP_FRAME_COUNT)
  print("%s 1 has %d frames" % (video, frame_end))
  return cap, frame_end

def frame_match_video(src_frame, dst_video):
  dst_cap, dst_frame_end  = video_load(dst_video) 

  orb = cv2.ORB_create()
  src_keypoints, src_descriptors = orb.detectAndCompute(src_frame, None)

  best_matches = 0
  best_frame = src_frame
  best_frame_no = 0
  while dst_cap.isOpened():
    ret, dst_frame = dst_cap.read()

    frame_count = dst_cap.get(cv2.CAP_PROP_POS_FRAMES)
    if frame_count == dst_frame_end:
      break
    if not ret:
      print('Failed to read %s frame %d' % (dst_video, frame_count))
      break

    dst_keypoints, dst_descriptors = orb.detectAndCompute(dst_frame, None)
    matches = match_features(src_descriptors, dst_descriptors)
    print(f'Matching to dst_video frame {frame_count}, matches={matches}')
    if matches > best_matches:
      best_matches = matches
      best_frame = dst_frame
      best_frame_no = frame_count
  print(f'Best matched frame {best_frame_no}, matches = {best_matches}')
  return best_matches, best_frame

def video_match(video1, video2):
  cap, frame_end  = video_load(video1) 

  while cap.isOpened():
    ret, frame = cap.read()

    frame_count = cap.get(cv2.CAP_PROP_POS_FRAMES)
    if frame_count == frame_end:
      break
    if not ret:
      print('Failed to read %s frame %d' % (video1, frame_count))
      break

    matches, matched_frame = frame_match_video(frame, video2)
    cv2.imshow('Src Frame', frame)
    cv2.imshow('Dst Frame', matched_frame)
    if cv2.waitKey(1000) == ord('q'):
      break

  cap.release()
  cv2.destroyAllWindows()

def main(argv=None):
  if argv is None:
      argv=sys.argv
  print('OpenCV version:', cv2.__version__)

  src = "IMG_0054.MOV"
  dst = "IMG_0290.MOV"
  video_match(src, dst)

if __name__ == '__main__':
  sys.exit(main())
