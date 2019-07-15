prog = ReadAlphabets("OSP.ab");
system = "OSP";
outDir = "../test-out/"+system+"-MP";

CheckProgram(prog);

#First generate the wrapper, the Makefile and the "WriteC" code
generateWrapper(prog, system, outDir);
#generateMakefile(prog, system, outDir);
generateWriteC(prog, system, outDir);
generateWriteC(prog, system, outDir+"/WriteC");

# Next generate a number of scheduled codes.
#  The first version does not set the spacetime Map
#  For sach we produce the OSP.c file in a separate subdirectory

generateScheduledCode(prog, system, outDir+"/S1");

setSpaceTimeMap(prog, system, "C", "(i,j->j-i,j)");
generateScheduledCode(prog, system, outDir+"/S2");

setSpaceTimeMap(prog, system, "C", "(i,j->j-i,N-j)");
generateScheduledCode(prog, system, outDir+"/S3"); # reverse S2 (PASSED tester2 and tester3 (max time t3: ~3E-4 sec))

setSpaceTimeMap(prog, system, "C", "(i,j->j,N-i)");
generateScheduledCode(prog, system, outDir+"/S4"); # triangles (PASSED tester2 and tester3 (max time t3: ~3E-4 sec))

setSpaceTimeMap(prog, system, "C", "(i,j->N-i,j)");
generateScheduledCode(prog, system, outDir+"/S5"); # reverse triangles (PASSED tester2 and tester3 (max time t3: ~3E-4 sec))
