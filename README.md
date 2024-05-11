# Wallace

Neural Darwinism doodles inspired by the work of William Calvin.

## Classes

*MiniColumn* - The fundimental unit
    - *self.state* - The current action potential

    - *function* - Describes firing frequency. Takes input.


*MacroColumn* - A bundle of 39 minicolumns
    - *self.columns* - A pointer to an array of 39 MiniColumns
    - *self.neighbors* - An array of six pointers to the surrounding MacroColumns


*PlayingField* - A two dimensional array of MacroColumns
    - ?
