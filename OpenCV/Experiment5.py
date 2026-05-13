import cv2
img = cv2.imread('OpenCV/photo.jpg')
h, w = img.shape[:2]
M_cw = cv2.getRotationMatrix2D((w/2, h/2), -90, 1)   # clockwise
M_ccw = cv2.getRotationMatrix2D((w/2, h/2), 90, 1)   # counter
rot_cw = cv2.warpAffine(img, M_cw, (w, h))
rot_ccw = cv2.warpAffine(img, M_ccw, (w, h))
cv2.imshow('Clockwise', rot_cw)
cv2.imshow('Counter', rot_ccw)
cv2.waitKey(0)