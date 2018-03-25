/*

使い方:

1.コマンドライン引数から操作する場合
f_raname 変更前のファイル名 変更後のファイル名

2.

*/

#include <stdio.h>
#define FILENAMELENGTH 260

/*ファイルを開けなかった場合は1,開いた場合は0を返す*/
int searchFile(FILE *fp,const char *filename)
{
  if((fp = fopen(filename,"r")) == NULL) {
    return 0; //ファイルを開けなった(ファイルがなかったことにする)
  } else {
    fclose(fp);
    return 1; //ファイルを開けた
  }
}

int renameFile(FILE *fp,const char *prefilename,const char *filename)
{
  if(searchFile(fp,filename)){
    printf("ファイル名が被りました。ファイル名の変更は行いません。\n");
    return 1; //変更後のファイル名が既存のファイル名と被った
  }

  if(rename(prefilename,filename) == 0){
    printf("ファイル名の変更に成功しました。\n");
    return 0; //ファイル名変更成功
  } else {
    printf("ファイル名の変更に失敗しました。\n");
    return 1; //ファイル名変更失敗
  }
}

int main(int argc, char const *argv[]) {
  FILE *fp;
  char prefilename[FILENAMELENGTH];
  char filename[FILENAMELENGTH];

  if(argc == 3) {  //コマンドライン引数を受け取った場合
    renameFile(fp,argv[1],argv[2]);
    return 0;
  } else if(argc > 3){
    printf("コマンドライン引数が多すぎます。\n\n");
  }

  printf("変更前のファイル名:");
  scanf("%s",prefilename);
  if(!searchFile(fp,prefilename)){
    printf("その名前のファイルは存在しません。プログラムを終了します。\n");
    return 1;
  }

  printf("変更後のファイル名:");
  scanf("%s",filename);
  renameFile(fp,prefilename,filename);

  printf("プログラムを終了します。\n");
  return 0;
}

