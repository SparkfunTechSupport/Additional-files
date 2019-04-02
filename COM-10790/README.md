This is some simple code for connecting the SparkFun COM-10790 encoder to an Arduino and counting pulses.

The COM-10790 encode will produce 200 pulses per full rotation. It's important to know that this encoder can not tell you what
direction it's traveling and it always counts up no matter what direction it's moving. That means if you rotate the encoder 
1/2 full rotation clockwise and then rotate it 1/2 full rotation it will register 200 pulses and not zero. 
