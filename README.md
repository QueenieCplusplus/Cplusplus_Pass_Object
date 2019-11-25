# Cplusplus_Pass_Object
pass by Val, pass by Ref

所謂運算子多載，其實就是說類別中的多個方法，多載的英文 overload，即類別聆聽到輸入的參數，配合約束型別限制的引數，而選用適用的運算式，

                         將(輸入) -> 輸出

                         (輸入的型別 輸入)：輸出的型別

在程式設計中，當我們意圖要 define ops，初衷其實是要為 Class 或是 Structure 提供一慣用寫法，例如 a=b+c，故針對引數 Argument 傳入運算子函數

# Pass Obj by Val

適用於小型物件，1 到 4 個字組，推薦使用，因於存取效能會比 pass by ref 還快。

範例：

            void Point::operator+=(Point data);
            
            

# Pass Obj by Ref

適用於大型物件，例如 Matrix 矩陣的物件或是 Array 陣列的物件，亦適合 LinkedList 串列的物件。

範例：


            Matrix operator+(const Matrix&, const Matrix&);
            
            

TBD...尚未完成。
