import cv2
import numpy as np
img1 = cv2.imread('OpenCV/photo.jpg')
img2 = cv2.imread('OpenCV/images.jpg')
orb = cv2.ORB_create()
kp1, des1 = orb.detectAndCompute(img1, None)
kp2, des2 = orb.detectAndCompute(img2, None)
bf = cv2.BFMatcher(cv2.NORM_HAMMING)
matches = bf.knnMatch(des1, des2, k=2)
good = []
for m,n in matches:
    if m.distance < 0.75*n.distance:
        good.append(m)
src_pts = np.float32([kp1[m.queryIdx].pt for m in good]).reshape(-1,1,2)
dst_pts = np.float32([kp2[m.trainIdx].pt for m in good]).reshape(-1,1,2)
H, _ = cv2.findHomography(src_pts, dst_pts, cv2.RANSAC, 5.0)
warped = cv2.warpPerspective(img1, H, (img2.shape[1], img2.shape[0]))
cv2.imshow('Homography', warped)
cv2.waitKey(0)