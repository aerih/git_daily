function y=PID_access(para)
%PID�������ܵ�ָ�����
kp=para(:,1);ki=para(:,2);kd=para(:,3);
[~,~,ts,sigma]=PID_sim(kp,ki,kd,false);
y=log(ts/5e-2+1)+log(sigma/1e-2+1);
end
