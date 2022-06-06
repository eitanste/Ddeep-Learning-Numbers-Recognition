# Ddeep-Learning-Numbers-Recognition
This program can be used for identifying handwritten digits. The program will receive as input a picture of a digit between 0 and 9 and return as output the digit that was detected. We do this by building a model of a neural network. In order to implement the model, I implemented some useful classes such as a matrix, a network layer and an activation function. The network will reach 96 percent accuracy in digit recognition.
To run the program, you can compile it by runing -$ make mlpnetwork, with the provided make file, and run it from the CMD by the following line - $ ./mlpnetwork w1 w2 w3 w4 b1 b2 b3 b4, when b_i & w_i is the paths for the waghts and biases provided in the Parameters file.
While runing, the program will ask the user to provide an image sorce, the Images files cn be found in the provided folder.
the program will print the image that where provided and the digit detected with its probobility.
the program will repite the past two steps until the user will provide "Q" as an input.
The idia for this program came from "3Blue1Brown" deep learning video in this link: https://www.youtube.com/watch?v=aircAruvnKk
