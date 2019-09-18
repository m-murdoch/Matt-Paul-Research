prog = ReadAlphabets("OSP.ab");
system = "OSP";
outDir = "../mappings/";
CheckProgram(prog);
AShow(prog, system);
NormalizeReduction(prog, system, "C");
RenameVariable(prog, system, "NR_C", "Main");
Normalize(prog);
CheckProgram(prog);

# -i,k,j (inner parallel) (AlphaZ parallelized the middle loop = wrong answer. Commented out for correct answer).
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->N-i,k,j)", "(i,j->N-i,i-1,j)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->N-i,j,j)");
#setParallel(prog, system, "", "2");
#setStatementOrdering(prog, system, "Main", "C");
#setMemorySpace(prog, system, "C", "C, Main"); (not used)
#generateScheduledCode(prog, system, outDir+"/-i_k_j_p");
#generateWrapper(prog, system, outDir+"/-i_k_j_p");

# -i,k,-j (inner parallel)
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->N-i,k,N-j)", "(i,j->N-i,i-1,N-j)");
#setSpaceTimeMap(prog, system, "C",    "(i,j->N-i,j-1,j+N)");
#setParallel(prog, system, "", "2");
#setStatementOrdering(prog, system, "Main", "C");
#setMemorySpace(prog, system, "C", "C, Main"); (not used)
#generateScheduledCode(prog, system, outDir+"/-i_k_-j_p");
#generateWrapper(prog, system, outDir+"/-i_k_-j_p");

# d,j,k (inner parallel) (AlphaZ included middle with private(j) also)
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
