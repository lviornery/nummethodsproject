ARRAYSIZE = 300;
condCoef = 1; %the higher this is, the lower the condition number
mdiag = rand(ARRAYSIZE,1); % all positive numbers between 0 and 1
mmat = condCoef*diag(mdiag);
kmat = rand(ARRAYSIZE,ARRAYSIZE)-.5; %off-diagonal elements of k are random between -5 and 5
kmat = 5*(kmat'*kmat) + condCoef*eye(ARRAYSIZE); %make the k matrix symetric positive definite
writematrix(mmat,'mmat.csv')
writematrix(kmat,'kmat.csv')
disp(['Condition is ' num2str(cond(inv(mmat)*kmat))]);
tic
    invm = inv(mmat);
    evalm = invm*kmat;
elapsed = 1e6*toc
tic
    evals = eig(evalm);
elapsed = 1e6*toc