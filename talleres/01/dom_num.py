"""
    Sea L una lista de n enteros, y L[i..j] la sublista de los elementos de L entre las posiciones i y j, inclusive.
    Escriba un programa que determine cuáles posiciones k satisfacen que L[k] es el máximo de L[k..n-1].
"""

INPUT_SEPARATOR = " "

def handle_user_input ():
    number_list = []
    
    str_input = input().strip()
    for str_number in str_input.split(INPUT_SEPARATOR):
        number_list.append(int(str_number))

    return number_list

"""
    This function uses a weird stuff that python does when (not)passing an optional argument
"""
def get_sublists_max_values (number_list, max_values_list=[]):
    if len(number_list) == 1:
        max_values_list.append(number_list[0])
        return max_values_list
    elif len(number_list) < 1:
        return max_values_list

    max_value = 0
    max_value_index = 0
    for i, number in enumerate(number_list):
        if max_value < number:
            max_value = number
            max_value_index = i

    max_values_list.append(max_value)

    return get_sublists_max_values(number_list[max_value_index + 1:])

def main ():
    number_list = handle_user_input()
    max_values_list = get_sublists_max_values(number_list)

    print(*max_values_list, end=" ")
    return

if __name__ == "__main__":
    main()
