,       Cell #0
> ,  		Cell #1

[        Start your loops with your cell pointer on the loop counter (#1 in our case)
	< +    Add 1 to #0
	> -    Subtract 1 from #1
]        End your loops with the cell pointer on the loop counter

At this point our program has added #1 to #0

To display the ASCII character we must subtract 48 to the value in #0.
We use a loop to compute 48 = 6 * 8.

++++ ++++  c1 = 8 and this will be our loop counter again
[
< --- ---  Add 6 to c0
> -        Subtract 1 from c1
]
< .