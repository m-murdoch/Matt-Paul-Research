prog = ReadAlphabets("OSP.ab");
system = "OSP";
outDir = "../test-out/"+system;

CheckProgram(prog);

AShow(prog, system);

## Space time maps that keep the k dimension as the innermost
#setSpaceTimeMap(prog, system, "C", "(i,j->j-i,j)"); 
#generateScheduledCode(prog, system, outDir+"/map_1"); # Map 1: Diagonals, top left to bottom right -> diagonal to top left corner
#setSpaceTimeMap(prog, system, "C", "(i,j->N-i,j)");
#generateScheduledCode(prog, system, outDir+"/map_2"); # Map 2: Rows(triangles), left to right -> bottom to top

## Space time maps that keep the k dimension as the innermost
#setSpaceTimeMap(prog, system, "C", "(i,j->j-i,j)"); 
#generateScheduledCode(prog, system, outDir+"/map_3"); # same as Map 1
#setSpaceTimeMap(prog, system, "C", "(i,j->N-i,j)"); 
#generateScheduledCode(prog, system, outDir+"/map_4"); # same as Map 2

## Space time maps that "permute the k dimension"

## Now for the  time maps that "permute the k dimension"
## For this we first do some preprocessing that "isolates"
## the reduction expression.  It introduces a new variable
## and remanes it to Main

NormalizeReduction(prog, system, "C");
RenameVariable(prog, system, "NR_C", "Main");
Normalize(prog);
CheckProgram(prog);

## Now for the mappings (you need to provide two functions)
## The first one won't work (can you tell me why)

#setSpaceTimeMap(prog, system, "Main", "(i,j,k->i,k,j)", "(i,j->i,0,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->i,j,j)");
#generateScheduledCode(prog, system, outDir+"/map_5"); # Doesn't compile. errors: long int -> int, redefines macros

## Will the next one work?

#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,k,j)", "(i,j->j-i,0,j)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->i,j,j)");
#generateScheduledCode(prog, system, outDir+"/map_6"); # Doesn't compile. errors: long int -> int, redefines macros

setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,N-i,k)", "(i,j->i,j,0)"); 
setSpaceTimeMap(prog, system, "C",    "(i,j->i,j,j)");
generateScheduledCode(prog, system, outDir+"/map_8");

## Other mapping ideas based on 2D mapping::
# Rows (S2) with k permuted to the OUTER loop:
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->k,j-i,j)", "(i,j->0,i,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,i,j)");

# Reverse Rows (S3) with k permuted to the OUTER loop:
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->k,j-i,N-j)", "(i,j->0,i,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,i,j)");

# Triangles (S4) with k permuted to the OUTER loop:
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->k,j,N-i)", "(i,j->0,i,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,i,j)");

# Reverse Triangles (S5) with k permuted to the OUTER loop:
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->k,N-i,j)", "(i,j->0,i,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,i,j)");

# Rows (S2) with k permuted to the MIDDLE loop:
# Covered above (map 6)

# Reverse Rows (S3) with k permuted to the MIDDLE loop:
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,k,N-j)", "(i,j->i,0,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->i,j,j)");

# Triangles (S4) with k permuted to the MIDDLE loop:
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,k,N-i)", "(i,j->i,0,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->i,j,j)");

# Reverse Triangles (S5) with k permuted to the MIDDLE loop:
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->N-i,k,j)", "(i,j->i,0,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->i,j,j)");

## If you simply generate code with this mapping (try it),
## the code will have two arrays, one for C and one for Main.
## This is wasteful and we should try to avoid it.

#setMemorySpace(prog, system, "C", "C, Main");
#generateScheduledCode(prog, system, outDir+"/map_7"); # Default maping, (i,j -> i,j), does NOT work.

#AShow(prog, system);

#generateVerificationCode(prog, system, outDir);
#generateWriteC(prog, system, outDir);
#generateWrapper(prog, system, outDir);
#generateMakefile(prog, system, outDir);
#generateScheduledCode(prog, system, outDir);
