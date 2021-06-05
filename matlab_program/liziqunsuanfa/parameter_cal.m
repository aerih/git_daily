function [f_infty,tp,ts,sigma]=parameter_cal(y,T0,delt_err,debug)
%y��ϵͳ�������
%T0�ǲ���ʱ�䣬���Խ��ʱ�����е�������ʵ��ʱ��
%delt_err�ǵ���ʱ�������
    M=size(y,1);N=size(y,2);%MΪ����ά�ȣ�NΪʱ�����г���
    f_infty=y(:,N);%��ֵ̬����
    err=y-f_infty*ones(1,N);%ͨ����ֵ̬�����������
    ferr=fliplr(abs(err));%����ȡ����ֵ
    [~,ts_i]=max(ferr>delt_err*f_infty,[],2);
    ts_i=N*ones(M,1)-ts_i;
    ts=ts_i*T0;%����ʱ��
    [fp,tp]=max(y,[],2);%��ֵ�ͺ�����ֵ
    tp=tp*T0;
    tp(abs(fp-f_infty)<1e-5)=NaN; %�������޳�����û�з�ֵʱ��
    sigma=(fp-f_infty)./f_infty;
    if debug && M==1 %�ǵ���ģʽ�²���ʾ
        disp(['ϵͳ��ֵ̬Ϊ',num2str(f_infty)])
        disp(['ϵͳ������Ϊ',num2str(sigma*100),'%'])
        if isnan(tp)
            disp('ϵͳ�����ڷ�ֵʱ��')
        else
            disp(['ϵͳ��ֵʱ��Ϊ',num2str(tp),'s'])
        end
        disp(['ϵͳ�ĵ���ʱ��Ϊ',num2str(ts),'s'])      %num2str������ת��Ϊ�ַ���
    end
end
