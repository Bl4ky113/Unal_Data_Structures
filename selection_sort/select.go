package main

import (
    "fmt"
)

func selectionSort (arr *[]int) {
    for i := 0; i < len(*arr); i++ {
        for j := i + 1; j < len(*arr); j++ {
            if (*arr)[j] < (*arr)[i] {
                temp := (*arr)[i]
                (*arr)[i] = (*arr)[j]
                (*arr)[j] = temp
            }
        }
    }

    return
}

func main () {
    var numInputs int
    fmt.Scanf("%d\n", &numInputs)

    inputs := make([]int, 0, numInputs)
    
    for i := 0; i < numInputs; i++ {
        var input int
        fmt.Scanf("%d\n", &input)

        inputs = append(inputs, input)
    }

    fmt.Printf("%v\n", inputs)
    
    selectionSort(&inputs)

    fmt.Printf("%v\n", inputs)

    return
}
