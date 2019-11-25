# Cplusplus_Pass_Object
pass by Val, pass by Ref

所謂運算子多載，其實就是說類別中的多個方法，多載的英文 overload，即類別聆聽到輸入的參數，配合約束型別限制的引數，而選用適用的運算式。

然而，運算子仍然不能視為成員函數，尤其是第一個運算元為內建型別時。

運算子函數必須遵從兩項規則：

1. 需要成為成員函數。(scope 作用域在類別中)

2. 至少帶有一個 self-defined 的 Argument。

                         將(輸入) -> 輸出

                         (輸入的型別 輸入)：輸出的型別
                         
範例：

                 enum DaysRemain { 1125, 1126, 1127};
                 
                 DaysRemain& operator++(DaysRemain& date)
                 {
                     return dr = (1127==date) ? 1125 : static_cast<DaysRemain>(date+1);
                 }



在程式設計中，當我們意圖要 define ops，初衷其實是要為 Class 或是 Structure 提供一慣用寫法，例如 a=b+c，故針對引數 Argument 傳入運算子函數

# Pass Obj by Val

適用於小型物件，1 到 4 個字組，推薦使用，因於存取效能會比 pass by ref 還快。

範例：

            void Point::operator+=(Point data);
                     

# Pass Obj by Ref

適用於大型物件，例如 Matrix 矩陣的物件或是 Array 陣列的物件，亦適合 LinkedList 串列的物件。
但仍然不推薦使用此種方式傳遞物件，可以用取代方案：

參照傳遞的範例：

by by const ref
>>>

            Matrix operator+(const Matrix&, const Matrix&);
            // 利用 const reference 傳遞物件資訊
            
            
return by ref
>>>

            // return 是 & 參照（記憶體位址）
            int& INT::operator+= int(const int& i)
            {
                int* j = elem;
                int* k = i.elem;
                *j++ += *k++;
                return *this;
            }           

取代方案：

            定義搬移數值的函數
             Matrix operator+(const Matrix& a, const Matrix& b)
             {
             
                Matrix res {a};
                return res+=b;
             
             }

# Return Vale 

基本上，運算子均會回傳結果值，可能傳回物件* 或是參照，但設計這樣的回傳型態，其實不是很好的做法，因為指標 * 會產生寫法問題，而利用指標 * 或是參照 ref 引用位於 free store 自由空間上的物件，會導致 HeapDump 記憶體洩漏的問題。
