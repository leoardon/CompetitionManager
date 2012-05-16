//
//  categories.hpp
//  
//
//  Created by Leo Ardon on 10/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _categories_hpp
#define _categories_hpp


//Benjamin Masculin
#define Mbenjamin_30_H 30

#define Mbenjamin_34_H 34

#define Mbenjamin_38_H 38

#define Mbenjamin_42_H 42

#define Mbenjamin_46_H 46

#define Mbenjamin_50_H 50 

#define Mbenjamin_60_H 60

#define Mbenjamin_66_H 66

#define Mbenjamin_PLUS66_L 66
 

//Benjamin Feminin
#define Fbenjamin_32_H 32

#define Fbenjamin_36_H 36

#define Fbenjamin_40_H 40

#define Fbenjamin_44_H 44

#define Fbenjamin_48_H 48

#define Fbenjamin_52_H 52

#define Fbenjamin_57_H 57

#define Fbenjamin_63_H 63

#define Fbenjamin_PLUS63_L 63
 

//Minime Masculin
#define Mminime_34_H 34

#define Mminime_38_H 38

#define Mminime_42_H 42

#define Mminime_46_H 46

#define Mminime_50_H 50

#define Mminime_55_H 55

#define Mminime_60_H 60

#define Mminime_66_H 66

#define Mminime_73_H 73

#define Mminime_PLUS73_L 73


//Minime Féminin
#define Fminime_36_H 32

#define Fminime_40_H 40

#define Fminime_44_H 44

#define Fminime_48_H 48

#define Fminime_52_H 52

#define Fminime_57_H 57

#define Fminime_63_H 63

#define Fminime_70_H 70

#define Fminime_PLUS70_L 70


//Cadet Masculin
#define Mcadet_46_H 46

#define Mcadet_50_H 50

#define Mcadet_55_H 55

#define Mcadet_60_H 60

#define Mcadet_66_H 66

#define Mcadet_73_H 73

#define Mcadet_81_H 81

#define Mcadet_90_H 90

#define Mcadet_PLUS90_L 90

//Cadet Feminine
#define Fcadet_40_H 40

#define Fcadet_44_H 44

#define Fcadet_48_H 48

#define Fcadet_52_H 52

#define Fcadet_57_H 57

#define Fcadet_63_H 63

#define Fcadet_70_H 70

#define Fcadet_PLUS70_L 70 

//Junior Masculin
#define Mjunior_55_H 55

#define Mjunior_60_H 60

#define Mjunior_66_H 66

#define Mjunior_73_H 73

#define Mjunior_81_H 81

#define Mjunior_90_H 90

#define Mjunior_100_H 100

#define Mjunior_PLUS100_L 100

//Juinor Feminin
#define Fjunior_44_H 44

#define Fjunior_48_H 48

#define Fjunior_52_H 52

#define Fjunior_57_H 57

#define Fjunior_63_H 63

#define Fjunior_70_H 70

#define Fjunior_78_H 78

#define Fjunior_PLUS78_L 78


//Senior Masculin
#define Msenior_60_H 60

#define Msenior_66_H 66

#define Msenior_73_H 73

#define Msenior_81_H 81

#define Msenior_90_H 90

#define Msenior_100_H 100

#define Msenior_PLUS100_L 100


//Senior Feminin
#define Fsenior_48_H 48

#define Fsenior_52_H 52

#define Fsenior_57_H 57

#define Fsenior_63_H 63

#define Fsenior_70_H 70

#define Fsenior_78_H 78

#define Fsenior_PLUS78_L 78


float MBenjamin[] = {Mbenjamin_30_H,Mbenjamin_34_H,Mbenjamin_38_H,Mbenjamin_42_H,Mbenjamin_46_H,Mbenjamin_50_H,Mbenjamin_60_H,Mbenjamin_66_H};
vector<float> VMBenjamin (MBenjamin, MBenjamin + sizeof(MBenjamin) / sizeof(int) + 1 );

float FBenjamin[] = {Fbenjamin_32_H,Fbenjamin_36_H,Fbenjamin_40_H,Fbenjamin_44_H,Fbenjamin_48_H,Fbenjamin_52_H,Fbenjamin_57_H,Fbenjamin_63_H};
vector<float> VFBenjamin (FBenjamin, FBenjamin + sizeof(FBenjamin) / sizeof(int) + 1 );

float MMinime[] = {Mminime_34_H,Mminime_38_H,Mminime_42_H,Mminime_46_H,Mminime_50_H,Mminime_55_H,Mminime_60_H,Mminime_66_H, Mminime_73_H};
vector<float> VMMinime (MMinime, MMinime + sizeof(MMinime) / sizeof(int) + 1 );

float FMinime[] = {Fminime_36_H,Fminime_40_H,Fminime_44_H,Fminime_48_H,Fminime_52_H,Fminime_57_H,Fminime_63_H,Fminime_70_H};
vector<float> VFMinime (FMinime, FMinime + sizeof(FMinime) / sizeof(int) + 1 );

float MCadet[] = {Mcadet_46_H,Mcadet_50_H,Mcadet_55_H,Mcadet_60_H,Mcadet_66_H,Mcadet_73_H,Mcadet_81_H,Mcadet_90_H};
vector<float> VMCadet (MCadet, MCadet + sizeof(MCadet) / sizeof(int) + 1 );

float FCadet[] = {Fcadet_40_H,Fcadet_44_H,Fcadet_48_H,Fcadet_52_H,Fcadet_57_H,Fcadet_63_H,Fcadet_70_H};
vector<float> VFCadet (FCadet, FCadet + sizeof(FCadet) / sizeof(int) + 1 );

float MJunior[] = {Mjunior_55_H,Mjunior_60_H,Mjunior_66_H,Mjunior_73_H,Mjunior_81_H,Mjunior_90_H,Mjunior_100_H};
vector<float> VMJunior (MJunior, MJunior + sizeof(MJunior) / sizeof(int) + 1 );

float FJunior[] = {Fjunior_44_H,Fjunior_48_H,Fjunior_52_H,Fjunior_57_H,Fjunior_63_H,Fjunior_70_H,Fjunior_78_H};
vector<float> VFJunior (FJunior, FJunior + sizeof(FJunior) / sizeof(int) + 1 );

float MSenior[] = {Msenior_60_H,Msenior_66_H,Msenior_73_H,Msenior_81_H,Msenior_90_H,Msenior_100_H};
vector<float> VMSenior (MSenior, MSenior + sizeof(MSenior) / sizeof(int) + 1 );

float FSenior[] = {Fsenior_48_H,Fsenior_52_H,Fsenior_57_H,Fsenior_63_H,Fsenior_70_H,Fsenior_78_H};
vector<float> VFSenior (FSenior, FSenior + sizeof(FSenior) / sizeof(int) + 1 );

vector<float> M[] = {VMBenjamin,VMMinime,VMCadet,VMJunior,VMSenior};
vector<vector<float> > masculin (M, M + sizeof(M) / sizeof(int) + 1 );

vector<float> F[] = {VFBenjamin,VFMinime,VFCadet,VFJunior,VFSenior};
vector<vector<float> > feminin (F, F + sizeof(F) / sizeof(int) + 1 );

#endif
