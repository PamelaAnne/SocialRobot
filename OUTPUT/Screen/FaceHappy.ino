void FaceHappy(){
  Serial1.print("CLS(0);"); // clear the screen with c color 
  Serial1.print("DR0;");    // the screen displays in upright way
  Serial1.println("PIC(5, 4, 5);");
  delay(1000);
}
