import cv2
import numpy as np
from matplotlib import pyplot as plt
 
img = cv2.imread('cheval.jpg')
blur = cv2.blur(img,(10,10))

cv2.imshow('image',img)
cv2.imshow('Blur',blur)

ret,thresh1 = cv2.threshold(img,127,255,cv2.THRESH_BINARY)
ret,thresh2 = cv2.threshold(img,127,255,cv2.THRESH_BINARY_INV)
ret,thresh3 = cv2.threshold(img,127,255,cv2.THRESH_TRUNC)
ret,thresh4 = cv2.threshold(img,127,255,cv2.THRESH_TOZERO)
ret,thresh5 = cv2.threshold(img,127,255,cv2.THRESH_TOZERO_INV)
 
thresh = ['img','thresh1','thresh2','thresh3','thresh4','thresh5']
 
for i in range(6):
    plt.subplot(2,3,i+1),plt.imshow(eval(thresh[i]),'gray')
    plt.title(thresh[i])
 
plt.show()

cv2.waitKey(0)
cv2.destroyAllWindows()