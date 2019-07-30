prog = ReadAlphabets("OSP.ab");
system = "OSP";
outDir = "./mappings/";

CheckProgram(prog);

AShow(prog, system);

# Diagonals, k is implicit
#setSpaceTimeMap(prog, system, "C", "(i,j->j-i,j)"); 
#generateScheduledCode(prog, system, outDir+"/diagonals");

# Columns, k is implicit
#setSpaceTimeMap(prog, system, "C", "(i,j->j,N-i)");
#generateScheduledCode(prog, system, outDir+"/columns"); 


## Space time maps that "permute the k dimension"

## Now for the  time maps that "permute the k dimension"
## For this we first do some preprocessing that "isolates"
## the reduction expression.  It introduces a new variable
## and remanes it to Main

NormalizeReduction(prog, system, "C");
RenameVariable(prog, system, "NR_C", "Main");
Normalize(prog);
CheckProgram(prog);


# Diagonals with k as INNER loop:
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,j,k)", "(i,j->j-i,j,0)"); 
#setSpaceTimeMap(prog, system, "C", "(i,j->j-i,j,j)"); 
#generateScheduledCode(prog, system, outDir+"/diagonals_k_inner"); # WORKS

# Columns with k as INNER loop:
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,N-i,k)", "(i,j->j,N-i,0)"); 
#setSpaceTimeMap(prog, system, "C", "(i,j->j,N-i,j)"); 
#generateScheduledCode(prog, system, outDir+"/columns_k_inner"); # WORKS


# Diagonals with k permuted to the MIDDLE loop:
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,j-k,j)", "(i,j->j-i,j,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,i-1,j)");
#generateScheduledCode(prog, system, outDir+"/diagonals_k_middle");  # WORKS

# Columns with k permuted to the MIDDLE loop:
setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,j-k,N-i)", "(i,j->j,j,N-i)"); 
setSpaceTimeMap(prog, system, "C",    "(i,j->j,i-1,N-i)"); 
generateScheduledCode(prog, system, outDir+"/columns_k_middle"); # Might work, produces too many S0 duplicates to know


# Diagonals with k permuted to the OUTER loop:
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->k,j-i,j)", "(i,j->0,i,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,i,j)");
#generateScheduledCode(prog, system, outDir+"/diagonals_k_outer");

# Columns with k permuted to the OUTER loop:
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->k,j,N-i)", "(i,j->0,i,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,i,j)");
#generateScheduledCode(prog, system, outDir+"/columns_k_outer");

## If you simply generate code with this this mapping (try it)
##  the code will have two arrays, one for C and one for Main.
##  This is wasteful and we should try to avoid it

#setMemorySpace(prog, system, "C", "C, Main");
#generateScheduledCode(prog, system, outDir+"/mem"); # Default maping, does NOT work. left to right -> top to bottom

#generateVerificationCode(prog, system, outDir);
#generateWriteC(prog, system, outDir);
#generateWrapper(prog, system, outDir);
#generateMakefile(prog, system, outDir);
