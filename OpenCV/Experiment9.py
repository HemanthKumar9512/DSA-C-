import cv2
import numpy as np
cap = cv2.VideoCapture('OpenCV/video.mp4')
pts_src = np.float32([[0,0], [300,0], [0,300], [300,300]])
pts_dst = np.float32([[50,0], [250,0], [0,250], [250,250]])
M = cv2.getPerspectiveTransform(pts_src, pts_dst)
while True:
    ret, frame = cap.read()
    if not ret: break
    warped = cv2.warpPerspective(frame, M, (300,300))
    cv2.imshow('Warped Video', warped)
    if cv2.waitKey(30) & 0xFF == ord('q'): break
cap.release()
cv2.destroyAllWindows()