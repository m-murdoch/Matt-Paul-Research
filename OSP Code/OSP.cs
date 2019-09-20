prog = ReadAlphabets("OSP.ab");
system = "OSP";
outDir = "../mappings/";

CheckProgram(prog);
AShow(prog, system);

######## The 4 original 2D mappings ########
# export LD_LIBRARY_PATH=/s/parsons/l/sys/intel/compilers_and_libraries/linux/lib/intel64

# d,j
#setSpaceTimeMap(prog, system, "C", "(i,j->j-i,j)");
#generateScheduledCode(prog, system, outDir+"/d_j");

# d,-j
#setSpaceTimeMap(prog, system, "C", "(i,j->j-i,N-j)");
#generateScheduledCode(prog, system, outDir+"/d_-j");

# j,-i
#setSpaceTimeMap(prog, system, "C", "(i,j->j,N-i)");
#generateScheduledCode(prog, system, outDir+"/j_-i");

# -i,j
#setSpaceTimeMap(prog, system, "C", "(i,j->N-i,j)");
#generateScheduledCode(prog, system, outDir+"/-i_j");

NormalizeReduction(prog, system, "C");
RenameVariable(prog, system, "NR_C", "Main");
Normalize(prog);
CheckProgram(prog);

######## The 19 3D mappings that were expected to work ########

# -i,j,k
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->N-i,j,k)", "(i,j->N-i,j,i-1)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->N-i,j,j)");
#generateScheduledCode(prog, system, outDir+"/-i_j_k");

# -i,j,-k
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->N-i,j,j-k)", "(i,j->N-i,j,0)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->N-i,j,j-i+1)");
#generateScheduledCode(prog, system, outDir+"/-i_j_-k");

# -i,k,j
setSpaceTimeMap(prog, system, "Main", "(i,j,k->N-i,k,j)", "(i,j->N-i,i-1,j)");
setSpaceTimeMap(prog, system, "C",    "(i,j->N-i,j,j)");
setParallel(prog, system, "", "2");
setStatementOrdering(prog, system, "Main", "C");
setMemorySpace(prog, system, "C", "C, Main"); (not used)
generateScheduledCode(prog, system, outDir+"/-i_k_j_p");
generateWrapper(prog, system, outDir+"/-i_k_j_p");

# -i,k,-j
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->N-i,k,N-j)", "(i,j->N-i,i-1,N-j)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->N-i,j-1,j+N)");
#setParallel(prog, system, "", "2");
#setStatementOrdering(prog, system, "Main", "C");
#setMemorySpace(prog, system, "C", "C, Main"); (not used)
#generateScheduledCode(prog, system, outDir+"/-i_k_-j_p");
#generateWrapper(prog, system, outDir+"/-i_k_-j_p");

# j,-i,k
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,N-i,k)", "(i,j->j,N-i,i-1)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,N-i,j)");
#generateScheduledCode(prog, system, outDir+"/j_-i_k");

# j,-i,-k
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,N-i,j-k)", "(i,j->j,N-i,0)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,N-i,j-i+1)");
#generateScheduledCode(prog, system, outDir+"/j_-i_-k");

# j,-k,i
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,j-k,i)", "(i,j->j,0,i)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,j-i+1,i-j)");
#generateScheduledCode(prog, system, outDir+"/j_-k_i");

# j,-k,-i
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,j-k,N-i)", "(i,j->j,0,N-i)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,j-i+1,N-i)");
#generateScheduledCode(prog, system, outDir+"/j_-k_-i");

# d,j,k (inner parallel)
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,j,k)", "(i,j->j-i,j,i-1)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j,j)");
#setParallel(prog, system, "", "2");
#setStatementOrdering(prog, system, "Main", "C");
#generateScheduledCode(prog, system, outDir+"/d_j_k_p");
#generateWrapper(prog, system, outDir+"/d_j_k_p");
#generateMakefile(prog, system, outDir+"/d_j_k_p");

# d,j,k (mid parallel)
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,j,k)", "(i,j->j-i,j,i-1)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j,j)");
#setParallel(prog, system, "", "1");
#setStatementOrdering(prog, system, "Main", "C");
#generateScheduledCode(prog, system, outDir+"/d_j_k_p1");
#generateWrapper(prog, system, outDir+"/d_j_k_p1");
#generateMakefile(prog, system, outDir+"/d_j_k_p1");

# d,j,-k
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,j,j-k)", "(i,j->j-i,j,0)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j,j-i+1)");
#generateScheduledCode(prog, system, outDir+"/d_j_-k");

# d,-j,k
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,N-j,k)", "(i,j->j-i,N-j,i-1)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,N-j,j)");
#generateScheduledCode(prog, system, outDir+"/d_-j_k");

# d,-j,-k
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,N-j,j-k)", "(i,j->j-i,N-j,0)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,N-j,j-i+1)");
#generateScheduledCode(prog, system, outDir+"/d_-j_-k");

# d,k,j
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,k,j)", "(i,j->j-i,i-1,j)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j,j)");
#generateScheduledCode(prog, system, outDir+"/d_k_j");

# d,-k,j
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,j-k,j)", "(i,j->j-i,0,j)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j-i+1,j)");
#generateScheduledCode(prog, system, outDir+"/d_-k_j");

# d,k,-j
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,k,N-j)", "(i,j->j-i,i-1,N-j)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j,N-j)");
#generateScheduledCode(prog, system, outDir+"/d_k_-j");

# d,-k,-j
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,j-k,N-j)", "(i,j->j-i,0,N-j)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j-i+1,N-j)");
#generateScheduledCode(prog, system, outDir+"/d_-k_-j");

# j,d,k
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,j-i,k)", "(i,j->j,j-i,i-1)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,j-i,j)");
#generateScheduledCode(prog, system, outDir+"/j_d_k");

# j,d,-k
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,j-i,j-k)", "(i,j->j,j-i,0)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,j-i,j-i+1)");
#generateScheduledCode(prog, system, outDir+"/j_d_-k");

# j,-k,d
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,j-k,j-i)", "(i,j->j,0,j-i)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,j-i+1,j-i)");
#generateScheduledCode(prog, system, outDir+"/j_-k_d");

##################### Memory Consolidation #####################

#setMemorySpace(prog, system, "C", "C, Main");
#generateScheduledCode(prog, system, outDir+"/memSpace"); # Default maping, (i,j -> i,j), does NOT work.

#AShow(prog, system);

#generateVerificationCode(prog, system, outDir);
#generateWriteC(prog, system, outDir);
#generateWrapper(prog, system, outDir);
#generateMakefile(prog, system, outDir);
#generateScheduledCode(prog, system, outDir);
