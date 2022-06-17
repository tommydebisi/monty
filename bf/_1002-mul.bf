++++ ++++        Get ascii code for 0 which is 48
[
    > +++ +++   Cell #1
    < -         Cell #0
]
>>
,           Cell #2 (User Input)
> ,  		Cell #3 (User Input)

<<      Cell #1
[               Remove 48 from User Input
    > ---- ----  cell #2
    > ---- ----  cell #3
    << ---- ---- cell #1
]

>           Cell #2 and it'll be our loop counter
[
    >       Move to Cell #3 and it's our loop counter
    [
        > +     Move and add 1 to Cell #4
        > +     Move and add 1 to Cell #5
        << -    Go back to Cell #3 and minus 1
    ]           Leaves loop if Cell #3 is 0

    [Still at Cell #3]
    >>           Move to cell #5 and it's our loop counter
    [
        << +    Move to Cell #3 and add 1
        >> -     Go back to Cell #5 and minus 1
    ]           Leaves loop if Cell #5 is 0

    <<< -         Go back to Cell #2 and minus 1
]

At this point our program has multiplied #2 and #3 to #4

To display the ASCII character we must add 48 to the value in #4.
We use a loop to compute 48 = 6 * 8.

++++ ++++  c2 = 8 and this will be our loop counter again
[
    >> +++ +++  Add 6 to Cell #4
    << -        Subtract 1 from c2
]
>> .
