'''
#Flipping the Image

from PIL import Image

#opening the Image
img = Image. open('divyam.JPG')

#transposing
transposed_img = img.transpose(Image.FLIP_LEFT_RIGHT)
#save it to a file in a Human unersstandable format
transposed_img.save('flipped_divyam.JPG')

print("Output image is done fliping")

#image enhancment technique
'''
import cv2

#read the image using CLAHE

img = cv2.imread('divyam.JPG')

#preparation for CLAHE

clahe = cv2.createCLAHE()

#convert it into gray scale image

gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

#apply enhancement

enh_img = clahe.apply(gray_img)

#save it to a file

cv2.imwrite('enhanced_img.JPG', enh_img)

print("Done enhancing")
cv2.imshow("IMAGE",enh_img)
 