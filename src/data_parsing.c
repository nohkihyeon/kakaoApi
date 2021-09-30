/*
 * Author   : Noh, Ki-Hyeon
 * Filename : data_parsing .c
 * Release  : 
 * Date     : 
 *
 * Description : Json Data Parsing Structure
 *
 * Notes :
 * ===================
 * History
 * ===================
 *
 */

#include "include.h"
int dataParsing(char* data){
	int i;
	char* afterData;
	afterData = strstr(data, "{");
	json_t *root;
	json_error_t error;

	root = json_loads(afterData, 0, &error);
	if(!root)
	{
		fprintf(stderr, "Error : on line %d : %s \n", error.line, error.text);
		return 1;
	}

	json_t *jsonData = json_object_get(root, "documents");
	if(json_is_array(jsonData)){
		const int length = json_array_size(jsonData);

		if(length > COMM_MAX)
		{
			error_handling("\nOut of index Error\n");
			return -1;
		}

		for(i=0; i<length; i++){
			json_t *jsonObject = json_array_get(jsonData, i);

			json_t *jsonAddress_name = json_object_get(jsonObject, "address_name");
			strcpy(dataSet.documents[i].address_name , json_string_value(jsonAddress_name));
			json_t *jsonCategory_group_code = json_object_get(jsonObject, "category_group_code");
			strcpy(dataSet.documents[i].category_group_code , json_string_value(jsonCategory_group_code));
			json_t *jsonCategory_group_name = json_object_get(jsonObject, "category_group_name");
			strcpy(dataSet.documents[i].category_group_name , json_string_value(jsonCategory_group_name));
			json_t *jsonCategory_name= json_object_get(jsonObject, "category_name");
			strcpy(dataSet.documents[i].category_name , json_string_value(jsonCategory_name));
			json_t *jsonDistance= json_object_get(jsonObject, "distance");
			strcpy(dataSet.documents[i].distance , json_string_value(jsonDistance));
			json_t *jsonId= json_object_get(jsonObject, "id");
			strcpy(dataSet.documents[i].id , json_string_value(jsonId));
			json_t *jsonPhone= json_object_get(jsonObject, "phone");
			strcpy(dataSet.documents[i].phone , json_string_value(jsonPhone));
			json_t *jsonPlace_name= json_object_get(jsonObject, "place_name");
			strcpy(dataSet.documents[i].place_name , json_string_value(jsonPlace_name));
			json_t *jsonPlace_url = json_object_get(jsonObject, "place_url");
			strcpy(dataSet.documents[i].place_url , json_string_value(jsonPlace_url));
			json_t *jsonRoad_address_name= json_object_get(jsonObject, "road_address_name");
			strcpy(dataSet.documents[i].road_address_name  , json_string_value(jsonRoad_address_name));
			json_t *jsonX= json_object_get(jsonObject, "x");
			strcpy(dataSet.documents[i].x , json_string_value(jsonX));
			json_t *jsonY= json_object_get(jsonObject, "y");
			strcpy(dataSet.documents[i].y , json_string_value(jsonY));
			printf("\naddress_name = %s\ncategory_group_code = %s\ncategory_group_name = %s\ncategory_name = %s\ndistance = %s\nid = %s\nphone = %s\nplace_name = %s\nplace_url = %s\nroad_address_name = %s\nx=%s\ny=%s\n\n\n", dataSet.documents[i].address_name, dataSet.documents[i].category_group_code, dataSet.documents[i].category_group_name, dataSet.documents[i].category_name, dataSet.documents[i].distance, dataSet.documents[i].id,dataSet.documents[i].phone, dataSet.documents[i].place_name, dataSet.documents[i].place_url,dataSet.documents[i].road_address_name,dataSet.documents[i].x, dataSet.documents[i].y);

		}
		json_t *jsonMetaData = json_object_get(root, "meta");
		json_t *jsonIs_end = json_object_get(jsonMetaData, "is_end");
		dataSet.meta.is_end = json_boolean_value(jsonIs_end);
		json_t *jsonPageable_count = json_object_get(jsonMetaData, "pageable_count");
		dataSet.meta.pageable_count = json_integer_value(jsonPageable_count);
		json_t *jsonTotal_count = json_object_get(jsonMetaData, "total_count");
		dataSet.meta.total_count = json_integer_value(jsonTotal_count);
		printf("Meta\nis_end = %d\npageable_count = %d\ntotal_count = %d\n",dataSet.meta.is_end, dataSet.meta.pageable_count, dataSet.meta.total_count);

		json_t *jsonSame_name = json_object_get(jsonMetaData, "same_name");
		json_t *jsonKeyword = json_object_get(jsonSame_name, "keyword");
		strcpy(dataSet.meta.same_name.keyword , json_string_value(jsonKeyword));

		json_t *jsonSelected_region = json_object_get(jsonSame_name, "selected_region");
		strcpy(dataSet.meta.same_name.selected_region , json_string_value(jsonSelected_region));

		printf("\nsame_name\nkeyword = %s\n\nselected_region = %s\n", dataSet.meta.same_name.keyword, dataSet.meta.same_name.selected_region);
	}
}

