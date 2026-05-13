import cv2
import numpy as np
img = cv2.imread('OpenCV/photo.jpg')
pts_src = np.float32([[0,0], [300,0], [0,300], [300,300]])
pts_dst = np.float32([[50,0], [250,0], [0,250], [250,250]])
M = cv2.getPerspectiveTransform(pts_src, pts_dst)
persp = cv2.warpPerspective(img, M, (300,300))
cv2.imshow('Perspective', persp)
cv2.waitKey(0)