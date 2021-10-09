#This code can detect and count eye blinks
#It requires dlib
#this can be further clubbed with many other face-related tasks

import numpy as np  
import cv2  
import dlib  
from scipy.spatial import distance as dist  
import argparse

   
#PREDICTOR_PATH = "C:\Users\mrao1\Downloads\blink-detection\shape_predictor_68_face_landmarks.dat"  
ap = argparse.ArgumentParser()
ap.add_argument("-p", "--shape-predictor", required=True,
	help="path to facial landmark predictor")
args = vars(ap.parse_args())
   
#predefining facial points
FULL_POINTS = list(range(0, 68))  
FACE_POINTS = list(range(17, 68))  
   
JAWLINE_POINTS = list(range(0, 17))  
RIGHT_EYEBROW_POINTS = list(range(17, 22))  
LEFT_EYEBROW_POINTS = list(range(22, 27))  
NOSE_POINTS = list(range(27, 36))  
RIGHT_EYE_POINTS = list(range(36, 42))  
LEFT_EYE_POINTS = list(range(42, 48))  
MOUTH_OUTLINE_POINTS = list(range(48, 61))  
MOUTH_INNER_POINTS = list(range(61, 68))  
   
EYE_AR_THRESH = 0.30 
EYE_AR_CONSEC_FRAMES = 2  
   
COUNTER_LEFT = 0  
TOTAL_LEFT = 0  
   
COUNTER_RIGHT = 0  
TOTAL_RIGHT = 0  
   
#defining a function to calculate ear    
def eye_aspect_ratio(eye):  
   # compute the euclidean distances between the two sets of  
   # vertical eye landmarks (x, y)-coordinates  
   A = dist.euclidean(eye[1], eye[5])  
   B = dist.euclidean(eye[2], eye[4])  
   
   # compute the euclidean distance between the horizontal  
   # eye landmark (x, y)-coordinates  
   C = dist.euclidean(eye[0], eye[3])  
   
   # compute the eye aspect ratio  
   ear = (A + B) / (2.0 * C)  
   
   # return the eye aspect ratio  
   return ear  
   
detector = dlib.get_frontal_face_detector()  
  
predictor = dlib.shape_predictor(args["shape_predictor"])
   
 # Start capturing the WebCam  
video_capture = cv2.VideoCapture(0)  
   
#driver code   
while True:  
   ret, frame = video_capture.read()  
   
   if ret:  
     gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)  
   
     rects = detector(gray, 0)  
   
     for rect in rects:  
       x = rect.left()  
       y = rect.top()  
       x1 = rect.right()  
       y1 = rect.bottom()  
   
       landmarks = np.matrix([[p.x, p.y] for p in predictor(frame, rect).parts()])  
   
       left_eye = landmarks[LEFT_EYE_POINTS]  
       right_eye = landmarks[RIGHT_EYE_POINTS]  
   
       left_eye_hull = cv2.convexHull(left_eye)  
       right_eye_hull = cv2.convexHull(right_eye)  
       cv2.drawContours(frame, [left_eye_hull], -1, (0, 255, 0), 1)  
       cv2.drawContours(frame, [right_eye_hull], -1, (0, 255, 0), 1)  
   
       ear_left = eye_aspect_ratio(left_eye)  
       ear_right = eye_aspect_ratio(right_eye)  
   
       cv2.putText(frame, "E.A.R. Left : {:.2f}".format(ear_left), (300, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 255), 2)  
       cv2.putText(frame, "E.A.R. Right: {:.2f}".format(ear_right), (300, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 255), 2)  
   
       if ear_left < EYE_AR_THRESH:  
         COUNTER_LEFT += 1  
       else:  
         if COUNTER_LEFT >= EYE_AR_CONSEC_FRAMES:  
           TOTAL_LEFT += 1  
           print("Left eye winked")  
         COUNTER_LEFT = 0  
   
       if ear_right < EYE_AR_THRESH:  
         COUNTER_RIGHT += 1  
       else:
           
         if COUNTER_RIGHT >= EYE_AR_CONSEC_FRAMES:  
           TOTAL_RIGHT += 1  
           print("Right eye winked")  
         COUNTER_RIGHT = 0  
   
     cv2.putText(frame, "Wink Left : {}".format(TOTAL_LEFT), (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 255), 2)  
     cv2.putText(frame, "Wink Right: {}".format(TOTAL_RIGHT), (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 255), 2)  
   
     cv2.imshow("Faces found", frame)  
   
   ch = 0xFF & cv2.waitKey(1)  
   
   if ch == ord('q'):  
     break  
   
cv2.destroyAllWindows()  
