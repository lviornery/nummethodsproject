ARRAYSIZE = 4;
mdiag = rand(ARRAYSIZE,1); % all positive numbers between 0 and 1
mmat = diag(mdiag);
kdiag = 5*rand(ARRAYSIZE,1); % all positive numbers between 0 and 5
kmat = diag(kdiag);
kod = 5*(rand(ARRAYSIZE,ARRAYSIZE)-.5); %off-diagonal elements of k are random
kod = kod - diag(diag(kod)); %set diagonal elements of off-diagonal matrix to 0
kmat = kmat + kod;
writematrix(mmat,'mmat.csv')
writematrix(kmat,'kmat.csv')
cond(inv(mmat)*kmat)