# read program and store the internal representation in variable prog
prog = ReadAlphabets("./Shadows.ab");

CheckProgram(prog);
 
# store string (corresponding to system name) to variable system
system = "Shadows";
 
# store output directory name to variable outDir
outDir = "./test-out2/"+system;
 
# print out the program using Show syntax
Show(prog);
 
# print out the program using AShow syntax
AShow(prog);
#NormalizeReduction(prog); This optimizes reductions already used and generates new AlphaZ script.
#AShow(prog);
#Comment out generate lines to see the generated AlphaZ code in a debugging type of state. 
# prints out the AST of the program (commented out)
#PrintAST(prog);
 
# generate codes (this is demand-driven, memoized code)
generateWriteC(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateMakefile(prog, system, outDir);
