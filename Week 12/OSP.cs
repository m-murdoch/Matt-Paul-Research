prog = ReadAlphabets("OSP.ab");
system = "OSP";
outDir = "../test-out/table/"+system;

CheckProgram(prog);
AShow(prog, system);

NormalizeReduction(prog, system, "C");
RenameVariable(prog, system, "NR_C", "Main");
Normalize(prog);
CheckProgram(prog);

##################### Table Entries #####################

# d,j,k      	  Diagonals (S2) k inner
setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,j,k)", "(i,j->j-i,j,i-1)"); 
setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j,j)");
generateScheduledCode(prog, system, outDir+"/djk");

# d,j,-k      	Diagonals (S2) -k inner
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,j,j-k)", "(i,j->j-i,j,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j,i-1)");
#generateScheduledCode(prog, system, outDir+"/dj_k");

# d,-j,k      	Reverse Diagonals (S3) k inner
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,N-j,k)", "(i,j->j-i,j,i-1)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j,j)");
#generateScheduledCode(prog, system, outDir+"/d_jk");

# d,-j,-k      	Reverse Diagonals (S3) -k inner
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,N-j,j-k)", "(i,j->j-i,j,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j,i-1)");
#generateScheduledCode(prog, system, outDir+"/d_j_k");

# j,-i,k   	    Columns (S4) k inner
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,N-i,k)", "(i,j->j,i,i-1)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,i,j)");
#generateScheduledCode(prog, system, outDir+"/j_ik");

# j,-i,-k   	  Columns (S4) -k inner
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,N-i,j-k)", "(i,j->j,i,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,i,i-1)");
#generateScheduledCode(prog, system, outDir+"/j_i_k");

# -i,j,k    	  Rows (S5) k inner
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->N-i,j,k)", "(i,j->i,j,i-1)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->i,j,j)");
#generateScheduledCode(prog, system, outDir+"/_ijk");

# -i,j,-k    	  Rows (S5) -k inner
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->N-i,j,j-k)", "(i,j->i,j,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->i,j,i-1)");
#generateScheduledCode(prog, system, outDir+"/_ij_k");

# d,k,j      	  Diagonals (S2) k middle
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,k,j)", "(i,j->j-i,i-1,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j,j)");
#generateScheduledCode(prog, system, outDir+"/dkj");

# d,-k,j     	  Diagonals (S2) -k middle
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,j-k,j)", "(i,j->j-i,j,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,i-1,j)");
#generateScheduledCode(prog, system, outDir+"/d_kj");  # WORKS

# d,k,-j    	  Reverse Diagonals (S3) k middle
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,k,N-j)", "(i,j->j-i,i-1,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,j,j)");
#generateScheduledCode(prog, system, outDir+"/dk_j");

# d,-k,-j    	  Reverse Diagonals (S3) -k middle
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-i,j-k,N-j)", "(i,j->j-i,j,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j-i,i-1,j)");
#generateScheduledCode(prog, system, outDir+"/d_k_j");

# j,-k,-i    	  Columns (S4) -k middle
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j,j-k,N-i)", "(i,j->j,j,i)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,i-1,i)");
#generateScheduledCode(prog, system, outDir+"/j_k_i");

# -i,-k,j    	  Rows (S5) -k middle
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->N-i,j-k,j)", "(i,j->i,j,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->i,i-1,j)");
#generateScheduledCode(prog, system, outDir+"/_i_kj");

# k,d,j      	  Diagonals (S2) k outer
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->k,j-i,j)", "(i,j->i-1,j-i,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,j-i,j)");
#generateScheduledCode(prog, system, outDir+"/kdj");

# -k,d,j     	  Diagonals (S2) -k outer
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-k,j-i,j)", "(i,j->j,j-i,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->i-1,j-i,j)");
#generateScheduledCode(prog, system, outDir+"/_kdj");

# k,d,-j     	  Reverse Diagonals (S3) k outer
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->k,j-i,N-j)", "(i,j->i-1,j-i,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->j,j-i,j)");
#generateScheduledCode(prog, system, outDir+"/kd_j");

# -k,d,-j    	  Reverse Diagonals (S3) -k outer
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-k,j-i,N-j)", "(i,j->j,j-i,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->i-1,j-i,j)");
#generateScheduledCode(prog, system, outDir+"/_kd_j");

# -k,j,-i    	  Columns (S4) -k outer
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-k,j,N-i)", "(i,j->j,j,i)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->i-1,j,i)");
#generateScheduledCode(prog, system, outDir+"/_kj_i");

# -k,-i,j    	  Rows (S5) -k outer
#setSpaceTimeMap(prog, system, "Main", "(i,j,k->j-k,N-i,j)", "(i,j->j,i,j)"); 
#setSpaceTimeMap(prog, system, "C",    "(i,j->i-1,i,j)");
#generateScheduledCode(prog, system, outDir+"/_k_ij");


##################### Memory Consolidation #####################

#setMemorySpace(prog, system, "C", "C, Main");
#generateScheduledCode(prog, system, outDir+"/memSpace"); # Default maping, (i,j -> i,j), does NOT work.

#AShow(prog, system);

#generateVerificationCode(prog, system, outDir);
#generateWriteC(prog, system, outDir);
#generateWrapper(prog, system, outDir);
#generateMakefile(prog, system, outDir);
#generateScheduledCode(prog, system, outDir);
