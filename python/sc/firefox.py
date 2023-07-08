import time
import pyautogui
from selenium import webdriver
from selenium.webdriver.firefox.options import Options

N = 1
page_load_time=5

geckodriver = '/home/rcnjko/geckodriver'
firefox = '/usr/bin/firefox-esr'
url = 'https://www.google.com'

options = Options()
options.binary_location = firefox
driver = webdriver.Firefox(options=options)
driver.get(url)

time.sleep(page_load_time)
window_size = driver.get_window_size()

for i in range(N):
  # Capture screenshot
  screenshot = pyautogui.screenshot(region=(0, 0, window_size["width"], window_size["height"]))
  screenshot.save(f"screenshot_{i}.png")

  # Send the right arrow key to the window
  body = driver.find_element_by_css_selector('body')
  body.send_keys(Keys.ARROW_RIGHT)

  time.sleep(page_load_time)

driver.quit()
