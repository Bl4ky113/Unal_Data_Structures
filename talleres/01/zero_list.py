"""
 * Sea L una lista de enteros no negativos. Se puede aplicar sobre L, tantas veces como se desee, la siguiente operación:
 *  - Seleccionar una posición k de L entre la primera y la penúltima, inclusive.
 *  - Restar una unidad a L[k] y a L[k+1].
 * Escriba un programa que decida si, aplicando la operación anteriormente definida, es posible transformar L en una lista de ceros.
"""

INPUT_SEPARATOR = " "
CORRECT_OUTPUT = "SI"
INCORRECT_OUTPUT = "NO"

def handle_user_input ():
    number_list = []
    
    str_input = input().strip()
    for str_number in str_input.split(INPUT_SEPARATOR):
        number_list.append(int(str_number))

    return number_list

def check_zero_list (number_list):
    dec_number = 0

    for i in range(len(number_list) - 1):
        dec_number = number_list[i] * -1
        number_list[i] = 0
        number_list[i + 1] += dec_number

        if (number_list[i + 1] <= 0 and i + 1 == len(number_list)):
            return False

    if number_list[-1] != 0:
        return False

    return True

def main ():
    number_list = handle_user_input()
    is_list_zero = check_zero_list(number_list)

    print(CORRECT_OUTPUT) if is_list_zero else print(INCORRECT_OUTPUT)
    return

if __name__ == "__main__":
    main()
