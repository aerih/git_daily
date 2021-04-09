%run('C:\Users\Administrator\git_program\matlab_program\adptive_control\simlink13.slx');
for j=1:150
    [simOut,fm] = sim('simlink13.slx',[0,10]);
    %gama1 = ones(1001,1)*100;
    %gama2 = ones(1001,1)*100;
    %gama1 = gama1+ones(1001,1)*50;
    gama2 = gama2+ones(1001,1)*5;

    simin = [t1,gama1,gama2];

    chaotiao_ptg = 1.1;     %�����ٷֱ�
    st_length = 300;        %ͳ�����еĳ���
    p_limit = 0.027;            %���˷����Ƶ���ֵ

    e=(pm.data-pr).^2;      %��������¼�˸�����ֵ��Ӧ�ķ���
    [m,n] = size(e);        %��ȡ���е��к���
    A_pr = pm.data((m-301):(m-1));      %�������������ǵ��ڳ���50�ģ�������������������50��������̬������̬��Ӧ�ÿ�����������ѡ����������ֵ��Ϊ����ֵ
    pr = sum(A_pr(:))/300;
    dt = max(pm.time)/length(pm.time);      %����ʱ����

    %ѭ������st_length������ʱ�����У�ֱ�����ַ������ĳ����ֵ��ֹͣѭ����
    for st_index = 1:m-st_length  %�������п�ʼ������
        index_range = st_index:st_index+st_length;  
        se = e(index_range);        %����������500�����еķ����¼                      
        sum_se = sum(se(:));        %��������з���ĺ�
        average = sum_se/st_length;
        if average <= p_limit
            data_Arr(iend) = st_index*dt;
            iend = iend + 1;
            for i = 1:st_index+st_length    %�ж������Ƿ���ڳ���������Ԥ�ڣ������Ļ�ɾ����¼��ֵ
                if pm.data(i)> pr*chaotiao_ptg
                    iend = iend - 1;
                    data_Arr(iend) = 0;
                    cue1 = "�����ˣ���������"
                    break;
                end
            end
            break;
        end
        if st_index == m-st_length
            cue2 = "δ�ҵ�������"
        end
    end
    cue3 = j
end