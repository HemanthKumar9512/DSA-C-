import cv2
cap = cv2.VideoCapture('OpenCV/video.mp4')
while True:
    ret, frame = cap.read()
    if not ret: break
    cv2.imshow('Frame', frame)
    # Slow motion: waitKey(100), Fast motion: waitKey(1)
    if cv2.waitKey(300) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()