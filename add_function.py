# bash bin/python3
import pathlib
import os
import shutil
import subprocess
from time import sleep
from tkinter import Tk  # Python 3

MACROS_PATH = "/home/natanvek/0-COMPUTER/0-PROGRAMACION/8-COMPETENCIA/Template/macros.cpp"

def main():
    # Carpeta donde se ubica el script
    path_script = pathlib.Path(__file__).parent

    print("name y prefix son una sola palabra, pero descripcion puede ser mas")
    
    name = input("nombre de la funcion: ") 

    # Carpeta donde se ubica el script
    parent_dir = os.path.join(path_script, 'snippets')

    # Pega en el path el nombre de la carpeta
    path = os.path.join(parent_dir, name + ".cpp") 
    
    # si ya existe esa carpeta se rompe todo
    if os.path.exists(path) : 
        print("este ejercicio ya existe perrachon")
        sleep(2)
        return
    else : 
        template_library = os.path.join(parent_dir, "template_library.cpp")
        with open(path, 'w') as newcpp:
            newcpp.write(f'#include "{MACROS_PATH}"\n')
            newcpp.write('//-----------------------------\n\n')
            with open(template_library, 'r') as template_file:
                shutil.copyfileobj(template_file, newcpp)

    prefix = input("prefix: ") 
    description = input("description: ") 

    body = Tk().clipboard_get()

    # Read in the file
    with open(path, 'r') as file :
        filedata = file.read()

    # Replace the target string
    filedata = filedata.replace('name:', f'name: {name}')
    filedata = filedata.replace('prefix:', f'prefix: {prefix}')
    filedata = filedata.replace('description:', f'description: {description}')

    # Write the file out again
    with open(path, 'w') as file:
        file.write(filedata)

    with open(path, 'a') as file:
        file.write(body)


    # Ejecutar make_snippets para actualizar los snippets de vscode
    try:
        subprocess.run(['python3', os.path.join(path_script, 'make_snippets.py')], check=True)
    except subprocess.CalledProcessError as e:
        print("Error ejecutando make_snippets")
        sleep(2)

if __name__ == "__main__":
    main()

