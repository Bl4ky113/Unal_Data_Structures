"""
    Un grupo de n personas está sentado en círculo. Iniciando en la primera persona y en sentido horario, 
    se numeran las personas hasta llegar al número k; si se completa el círculo y no se ha llegado a este número, 
    se continua con la primera persona. La k-ésima persona es retirada del círculo. El proceso se repite en 
    múltiples rondas, iniciando la cuenta desde la persona siguiente a la última en ser retirada, hasta que quede solamente una.
    Su tarea es escribir un programa para determinar quién será la última persona que quede en el círculo.
"""

INPUT_SEPARATOR = " "

def handle_user_input ():
    people_list = []
    people_number = 0
    people_loop = 0

    people_number, people_loop = input().strip().split(INPUT_SEPARATOR)
    
    str_input = input().strip()
    for str_person in str_input.split(INPUT_SEPARATOR):
        people_list.append(str_person)

    return people_list, int(people_number), int(people_loop)

def duck_duck_goose (people_list, people_loop):
    current_index = 0
    while len(people_list) > 1:
        to_delete_index = (((current_index + people_loop) % len(people_list)) - 1)

        if to_delete_index < 0:
            to_delete_index = len(people_list) - (to_delete_index * -1)

        del people_list[to_delete_index]
        current_index = to_delete_index

    return people_list[0]

def main ():
    people_list, people_number, people_loop = handle_user_input()

    last_person = duck_duck_goose(people_list, people_loop)
    print(last_person)
    return

if __name__ == "__main__":
    main()
