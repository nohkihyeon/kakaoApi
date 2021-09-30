/*==============================================================================
 * Created by kihyeon, Noh
 * for kakao api 키워드 검색
 *=============================================================================*/

/* json ex)
{
	"documents": [
	{
		"address_name": "서울 종로구 관훈동",
			"category_group_code": "AT4",
			"category_group_name": "관광명소",
			"category_name": "여행 \u003e 관광,명소 \u003e 테마거리",
			"distance": "",
			"id": "8053121",
			"phone": "",
			"place_name": "인사동거리",
			"place_url": "http://place.map.kakao.com/8053121",
			"road_address_name": "",
			"x": "126.98561901337",
			"y": "37.5733610774662"
	},
		...
	],
	"meta": {
		"is_end": true,
		"pageable_count": 10,
		"same_name": {
			"keyword": "insadong",
			"region": [],
			"selected_region": ""
		},
		"total_count": 10
	}
}
*/

#define DEFAULT_SIZE 512
#define COMM_MAX     5

#ifndef __DATASET_H__
#define __DATASET_H__

typedef struct Document_t{
	char        id                  [DEFAULT_SIZE]  ;
	char        place_name          [DEFAULT_SIZE]  ;
	char        category_group_code [DEFAULT_SIZE]  ;
	char        category_group_name [DEFAULT_SIZE]  ;
	char        category_name       [DEFAULT_SIZE]  ;
	char        phone               [DEFAULT_SIZE]  ;
	char        address_name        [DEFAULT_SIZE]  ;
	char        road_address_name   [DEFAULT_SIZE]  ;
	char        x                   [DEFAULT_SIZE]  ;
	char        y                   [DEFAULT_SIZE]  ;
	char        place_url           [DEFAULT_SIZE]  ;
	char        distance            [DEFAULT_SIZE]  ;
} Document ;

typedef struct Region_t {
	char        region              [DEFAULT_SIZE]  ;
} Region ;

typedef struct SameName_t {
	Region      regions             [COMM_MAX]      ;
	char        keyword             [DEFAULT_SIZE]  ;
	char        selected_region     [DEFAULT_SIZE]  ;
} SameName ;

typedef struct Meta_t {
	int         total_count                         ;
	int         pageable_count                      ;
	short       is_end                              ;
	SameName    same_name                           ;
} Meta ;

typedef struct DataSet_t {
	Document    documents           [COMM_MAX]      ;
	Meta        meta                                ;
} DataSet ;
#endif
