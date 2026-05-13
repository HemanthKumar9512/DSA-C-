import cv2
import numpy as np
img = cv2.imread('OpenCV/photo.jpg')
h, w = img.shape[:2]
M = np.float32([[1, 0, 50], [0, 1, 100]])   # shift right 50, down 100
moved = cv2.warpAffine(img, M, (w, h))
cv2.imshow('Moved', moved)
cv2.waitKey(0)