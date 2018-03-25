/*

�g����:

1.�R�}���h���C���������瑀�삷��ꍇ
f_raname �ύX�O�̃t�@�C���� �ύX��̃t�@�C����

2.

*/

#include <stdio.h>
#define FILENAMELENGTH 260

/*�t�@�C�����J���Ȃ������ꍇ��1,�J�����ꍇ��0��Ԃ�*/
int searchFile(FILE *fp,const char *filename)
{
  if((fp = fopen(filename,"r")) == NULL) {
    return 0; //�t�@�C�����J���Ȃ���(�t�@�C�����Ȃ��������Ƃɂ���)
  } else {
    fclose(fp);
    return 1; //�t�@�C�����J����
  }
}

int renameFile(FILE *fp,const char *prefilename,const char *filename)
{
  if(searchFile(fp,filename)){
    printf("�t�@�C���������܂����B�t�@�C�����̕ύX�͍s���܂���B\n");
    return 1; //�ύX��̃t�@�C�����������̃t�@�C�����Ɣ����
  }

  if(rename(prefilename,filename) == 0){
    printf("�t�@�C�����̕ύX�ɐ������܂����B\n");
    return 0; //�t�@�C�����ύX����
  } else {
    printf("�t�@�C�����̕ύX�Ɏ��s���܂����B\n");
    return 1; //�t�@�C�����ύX���s
  }
}

int main(int argc, char const *argv[]) {
  FILE *fp;
  char prefilename[FILENAMELENGTH];
  char filename[FILENAMELENGTH];

  if(argc == 3) {  //�R�}���h���C���������󂯎�����ꍇ
    renameFile(fp,argv[1],argv[2]);
    return 0;
  } else if(argc > 3){
    printf("�R�}���h���C���������������܂��B\n\n");
  }

  printf("�ύX�O�̃t�@�C����:");
  scanf("%s",prefilename);
  if(!searchFile(fp,prefilename)){
    printf("���̖��O�̃t�@�C���͑��݂��܂���B�v���O�������I�����܂��B\n");
    return 1;
  }

  printf("�ύX��̃t�@�C����:");
  scanf("%s",filename);
  renameFile(fp,prefilename,filename);

  printf("�v���O�������I�����܂��B\n");
  return 0;
}

