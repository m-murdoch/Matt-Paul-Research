prog = ReadAlphabets("BPMWin.ab");
system = "BPMWin";
outDir = "../test-out/toBPM/"+system+".v1";

CheckProgram(prog);

#First generated code (and wrapper & Makefile) with WriteC,
# but with the memory map that we need with Prerana's MPMML
#  Then jumped to the schedule that Nikolai needs

#Next used the following schedule (performance data in diag.out)
#setSpaceTimeMap(prog, system, "X", "(i1,j1,i2,j2->j1-i1,j1,i2,j2)");

#Next used the following - bottom to top - schedule (performance data in bt.out)
#setSpaceTimeMap(prog, system, "X", "(i1,j1,i2,j2->N-i1,j1,i2,j2)");

#Now for schedules that pull out the accumulation dimension(s)

#NormalizeReduction(prog, system, "X");
#Normalize(prog);
#  The first mapping is bottom to top (inner dimensions use SV schedule)
#setSpaceTimeMap(prog, system, "NR_X", "(i1,j1,i2,j2,k1,k2-> N-i1,j1,k1,i2,k2,j2)",
#									  "(i1,j1,i2,j2      -> N-i1,j1,i1-1,i2,-1,j2)");
#setSpaceTimeMap(prog, system, "X", "(i1,j1,i2,j2->N-i1,j1,j1,i2,M,j2)");

#  The next mapping is diagonal with k1 as the middle loop (inner dimensions use SV schedule)

#setSpaceTimeMap(prog, system, "NR_X", "(i1,j1,i2,j2,k1,k2 -> j1-i1,k1,j1,i2,k2,j2)",
#									  "(i1,j1,i2,j2       -> j1-i1,i1-1,j1,i2,-1,j2)");
#setSpaceTimeMap(prog, system, "X", "(i1,j1,i2,j2->j1-i1,j1,j1,i2,M,j2)");

#Now for the memory maps:

#setMemorySpace(prog, system, "X", "X, NR_X, NR_X_Alpha_Init");

# As you know this does not work -- the Initialization variable NR_X_Alpha_Init
# still has memory space NR_X.  The workaround for this bug is to manually edit
# the generated file, sorry.

#setMemoryMap(prog, system, "X", "X", "(i1,j1,i2,j2 -> j1,j1-i1,i2,j2)");
#setMemoryMap(prog, system, "NR_X_Alpha_Init", "X", "(i1,j1,i2,j2 -> j1,j1-i1,i2,j2)");
#setMemoryMap(prog, system, "NR_X", "X", "(i1,j1,i2,j2 -> j1,j1-i1,i2,j2)");

#print("Test");
AShow(prog, system);

generateWriteC(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateMakefile(prog, system, outDir);
#generateScheduledCode(prog, system, outDir);
