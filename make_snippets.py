import pathlib
import os

SNIPPET_FILE_PATH = "/home/natanvek/.config/Code/User/snippets/cpp.json"


def main():
    # Carpeta donde se ubica el script
    path_script = pathlib.Path(__file__).parent

    path_snippets = os.path.join(path_script, 'snippets')

    # Lista con los archivos de la carpeta
    code_library = os.listdir(path_snippets)

    snippets_file = open(SNIPPET_FILE_PATH, "w")

    snippets_file.write("{\n")
    for archivo in code_library:
        if(archivo.endswith(".cpp") and archivo != "template_library.cpp"):
            path_cpp = os.path.join(path_snippets, archivo)
            snippets_file.write(parser(path_cpp))
    snippets_file.write("}")
    snippets_file.close()
        
def parser(path):
    name = ""
    body = ""
    description = ""
    prefix = ""
    with open(path,'r') as file:
        for line in file:
            words = line.split()
            if(line == "//  body:\n"): break
            for i in range(len(words)):
                if words[i] == "name:" and i+1 < len(words): name = words[i+1]
                elif words[i] == "prefix:" and i+1 < len(words): prefix = words[i+1]
                elif(words[i] == "description:"):
                    for j in range(i+1, len(words)): description += words[j] + " "
                    if len(description) : description = description[:-1]
                
        for line in file:
            if(line[-1] == '\n'): line = line[:-1]
            body += f'\t\t\t\"{edit(line)}\", \n'
    
    block = ""
    block += f'\t"{edit(name)}": {{\n'
    block += f'\t\t"prefix": ["{edit(prefix)}", "libreria"],\n'
    block += f'\t\t"description": "{edit(description)}",\n'
    block += f'\t\t"body": [\n{body}\t\t]\n'
    block += f'\t}},\n'
    if(edit(name) == "") :
        popo = 45
    return block
    
def edit(str):
    str = str.replace("\t", "    ")
    str = str.replace("\\n", "\\\\n")
    str = str.replace('"', '\\"')
    return str

if __name__ == "__main__":
    main()