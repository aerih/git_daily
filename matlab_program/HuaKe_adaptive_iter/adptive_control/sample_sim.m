%run('C:\Users\Administrator\git_program\matlab_program\adptive_control\simlink13.slx');
data1_Arr = zeros(70,70);    %�½�һ���������ڴ�Ÿ���٤��ֵ��ʼ������ʱ��
data2_Arr = zeros(70,70);
for k=1:70
    gama1 = gama1+5;
    gama2 = 10;
    for j=1:70
        [simOut,fm] = sim('simlink13.slx',[0,5]);
        gama2 = gama2+10;
        chaotiao_ptg = 1.8;     %�����ٷֱ�
        st_length = 300;        %ͳ�����еĳ���
        p_limit = 0.03;         %���˷����Ƶ���ֵ

        e=(pm.data-pr).^2;      %��������¼�˸�����ֵ��Ӧ�ķ���
        [m,n] = size(e);        %��ȡ���е��к���
        A_pr = pm.data((m-301):(m-1));      %�������������ǵ��ڳ���50�ģ�������������������50��������̬������̬��Ӧ�ÿ�����������ѡ����������ֵ��Ϊ����ֵ
        pr = sum(A_pr(:))/300;
        dt = max(pm.time)/length(pm.time);      %����ʱ����

        %ѭ������st_length������ʱ�����У�ֱ�����ַ������ĳ����ֵ��ֹͣѭ����
        for st_index = 1:m-st_length  %�������п�ʼ������
            index_range = st_index:st_index+st_length;
            se = e(index_range);        %����������300�����еķ����¼                      
            sum_se = sum(se(:));        %��������з���ĺ�
            average = sum_se/st_length;
            if average <= p_limit
                data1_Arr(k,j) = st_index*dt;
                data2_Arr(k,j) = 50-pm.data(st_index+149);
                for i = 1:st_index+st_length    %�ж������Ƿ���ڳ���������Ԥ�ڣ������Ļ�ɾ����¼��ֵ
                    if pm.data(i)> pr*chaotiao_ptg
                        data1_Arr(k,j) = 0;
                        data2_Arr(k,j) = 0;
                        cue1 = "�����ˣ���������"
                        break;
                    end
                end
                break;
            end
            if st_index == m-st_length
                data1_Arr(k,j) = 0;
                data2_Arr(k,j) = 0;
                cue2 = "δ�ҵ�������"
            end
        end
        cue3 = [k j]
    end
end