import cv2
img = cv2.imread('OpenCV/photo.jpg')
blur = cv2.GaussianBlur(img, (5,5), 0)
cv2.imshow('Blurred', blur)
cv2.waitKey(0)