#cell = 10 will be used as a counter
++++ ++++ ++
#0: 6
[
	>++++ ++++ #Move to cell 1 and add 8
	      with every iteration
	<- #decrement cell 0
]
#cell 1 = 48
>+++ .
#cell 0: 4
<++++
[
	>++++
	<-
]
#cell 1 = 99
>.
#cell 0: 1
<+
[
	>++++
	<-
]
#cell 1 = 104
>+.
<++
[
	>++++
	<-
]
#cell 1 = 111
>-.
#print again whatever you just printed
.
---
.
