import cv2
import numpy as np
cap = cv2.VideoCapture(0)
while (1):
    _, frame = cap.read()

    # intialize the object
    detector = cv2.CascadeClassifier("haarcascade_smile.xml")

    # read the image and convert to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # perform the the face detection
    rects = detector.detectMultiScale(gray, scaleFactor=1.05,
                                      minNeighbors=5, minSize=(30, 30),
                                      flags=cv2.CASCADE_SCALE_IMAGE)

    # loop over the bounding boxes
    for (x, y, w, h) in rects:
        # draw the face bounding box on the image
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

    # display the camera
    cv2.imshow('Eye Detection ', frame)

    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break


cv2.destroyAllWindows()
cap.release()