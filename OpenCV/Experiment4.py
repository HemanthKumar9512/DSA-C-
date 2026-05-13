import cv2
img = cv2.imread('OpenCV/photo.jpg')
big = cv2.resize(img, None, fx=2, fy=2)
small = cv2.resize(img, None, fx=0.5, fy=0.5)
cv2.imshow('Bigger', big)
cv2.imshow('Smaller', small)
cv2.waitKey(0)