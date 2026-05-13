import cv2
import numpy as np
img = cv2.imread('OpenCV/photo.jpg')
rows, cols = img.shape[:2]
src = np.float32([[0,0], [cols-1,0], [0,rows-1]])
dst = np.float32([[50,0], [cols-100,0], [0,rows-50]])
M = cv2.getAffineTransform(src, dst)
affine = cv2.warpAffine(img, M, (cols, rows))
cv2.imshow('Affine', affine)
cv2.waitKey(0)