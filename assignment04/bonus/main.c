char *result = "Unknow";
int testing = 0x41424344; // "ABCD"
int main()
{
  char* pChar = (char*)&testing;
  if (pChar[0] == 'A'){
      result = "Big Endian";
  }
  else if (pChar[0] == 'D') {
      result = "Little Endian";
  }
  return 0;
}
