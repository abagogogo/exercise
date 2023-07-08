import pyautogui

def screenshot(window_title):
  """Takes a screenshot of the window with the given title and saves it as a PNG file."""
  pyautogui.screenshot(window_title + ".png")

def main():
  window_title = "test"
  for i in range(1):
    screenshot(window_title)

if __name__ == "__main__":
  main()
