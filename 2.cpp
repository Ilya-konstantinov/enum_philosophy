enum Bool{
    False,
    True
};

// Объявление без ключевого слова enum пришло из C
// Оно позволяет писать без EnumName::
// Но в настоящем проекте повышен риск коллизии имен
// Хотя если вы напишите хоть строчку того, что я описал ниже,
// Вас в рай не пустят.

class UInt8{
    Bool bits[8];

    UInt8(Bool _bits[]){
        for(size_t i = 0; i < 8; i++)
            bits[i] = _bits[i];
    }

    UInt8 operator+=(UInt8& other){
        Bool add[9];
        for(size_t i = 0; i < 9; i++)
            add[i] = Bool::False;    
        
        for (size_t i = 0; i < 8; i++){
            if (bits[i] == True && other.bits[i] == True){
                add[i+1] = True;
                bits[i] = False;
                other.bits[i] = False;
            }
            if (add[i] == True){
                if (bits[i] == False){
                    bits[i] = True;
                    add[i] = False;
                }
                else{
                    bits[i] = False;
                    add[i + 1] = True;
                }
            }
        }
        return *this;
    }
};



