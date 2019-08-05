def formatter(var):
    form = ["","",""]
    if var[1] != "k":
        for i in range(3):
            if var[1] == "i":
                if var[0] == "":
                    form[i] = "i"
                else:
                    form[i] = "N-i"
            elif var[1] == "j":
                if var[0] == "":
                    form[i] = "j"
                else:
                    form[i] = "N-j"
            else:
                    form[i] = "j-i"
    else:
        if var[0] == "":
            form[0] = "k"
            form[1] = "i-1"
            form[2] = "j"
        else:
            form[0] = "j-k"
            form[1] = "j"
            form[2] = "i-1"

    return form


def main():
    script = open("mappings.txt", "w+")
    map = ["","i","","j","","k"]
    for loop_1 in range(2):

        for outer in range(0,6,2):
            for middle in range(0,6,2):
                if middle == outer:
                    continue
                inner = 6 - outer - middle

                map[0] = ""
                for loop_2 in range(2):
                    map[2] = ""
                    for loop_3 in range(2):
                        map[4] = ""
                        for loop_4 in range(2):
                            outerf = formatter([map[outer], map[outer+1]])
                            middlef = formatter([map[middle], map[middle + 1]])
                            innerf = formatter([map[inner], map[inner + 1]])


                            script.write("# {}{},{}{},{}{}\n".format(map[outer], map[outer+1],map[middle],
                                                                     map[middle+1], map[inner], map[inner+1]))

                            script.write('#setSpaceTimeMap(prog, system, "Main", "(i,j,k->')
                            script.write('{},{},{})", '.format(outerf[0],middlef[0],innerf[0]))
                            script.write('"(i,j->{},{},{})");\n'.format(outerf[1],middlef[1],innerf[1]))

                            script.write('#setSpaceTimeMap(prog, system, "C",    "(i,j->{},{},{})");\n'.format(outerf[2], middlef[2], innerf[2]))

                            script.write('#generateScheduledCode(prog, system, outDir+"/{}{}_{}{}_{}{}");\n\n'.format(map[outer], map[outer+1],
                                                                                        map[middle], map[middle+1], map[inner], map[inner+1]))


                            map[4] = "-"
                        map[2] = "-"
                    if map[1] == "d":
                        break
                    map[0] = "-"

        map[1] = "d"


    script.close()
if __name__ == '__main__':
   main()
