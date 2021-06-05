function [Pg,fmin]=PSO(f,dimension,n,m,xmax,xmin,vmax,vmin)
%ȫ������Ⱥ�㷨,fΪĿ�꺯��,dimensionΪά��,nΪ����,mΪ��Ⱥ��ģ
%λ���޷�Ϊ[xmin,xmax]���ٶ��޷�Ϊ[vmin,vmax]
    Savef=zeros(n+1,1);
    SaveData=zeros(m,dimension,floor(n/10)+1);%��¼11����Ⱥ��λ��
    w=1;c1=2;c2=2;%�ٶȹ���ϵ��
    dt=0.3;%λ�Ʒ�����
    v=zeros(m,dimension);%��ʼ�ٶ�Ϊ0
    X=(xmax-xmin)*rand(m,dimension)+xmin;%��ʼλ������(-xmax,xmax)�ھ��ȷֲ�
    P=X;%PΪÿ������ÿ��������λ��
    last_f=f(X);
    [fmin,min_i]=min(last_f);%PgΪ���д��е�����λ�� 
    Pg=X(min_i,:);  %min_iΪ��ý�����±�
    Savef(1)=fmin;
    N=0;
    for i=1:n
        i
        v=w*v+c1*rand*(P-X)+c2*rand*(ones(m,1)*Pg-X);
        v=(v>vmax).*vmax+(v>=vmin & v<=vmax).*v+(v<vmin).*vmin;
        X=X+v*dt;
        X=(X>xmax).*xmax+(X>=xmin & X<=xmax).*X+(X<xmin).*xmin;  %��Χ���Ƶ����ã��жϴ�����ȷ��Ϊ1����Ϊ0
        new_f=f(X);%�µ�Ŀ�꺯��ֵ
        update_j=find(new_f<last_f);   %find��������Ѱ������ֵ,�����µıȾɵ�С����¼����
        P(update_j,:)=X(update_j,:);%����ÿ�����ӵ���ʷ����ֵ
        [new_fmin,min_i]=min(new_f);
        new_Pg=X(min_i,:);
        Pg=(new_fmin<fmin)*new_Pg+(new_fmin>=fmin)*Pg;  %����һ���жϵ����ã����С����ʷ�ͽ���ʷ�滻�����ڵ�ֵ
        last_f=new_f;%���浱ǰ�ĺ���ֵ
        fmin=min(new_fmin,fmin);%���º�����Сֵ
         Savef(i)=fmin;
         %if mod(i,floor(n/10))==0  %ÿ10����¼һ����Ⱥ������modȡ������floor����ȡ��
%          if mod(i,10)==0 
%              N=N+1;
%             SaveData(:,:,N)=X;
%          end
         w=w-i/n*0.7*w;
    end
%     for j=1:floor(n/10)
%         figure(j)
%         plot(SaveData(:,1,j),SaveData(:,2,j),'o');
%         xlim([-xmax,xmax])
%         ylim([-xmax,xmax])
%         axis tight
%     end
    figure
    plot(Savef','b-')
    disp(Pg)
    disp(fmin)
end

