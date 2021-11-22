# kakao Rest Api

kakao, REST API, Gson, C

카카오 REST API를 Gson을 통해 키워드 검색

1. 카카오 디벨로퍼 페이지에서 내 애플리케이션에서 인증 키를 발급
2. 요청 요구사항에 맞게 코드를 작성
3. 키워드 검색 시 해당 결과를 write

## kakao developers 
- [카카오디벨로퍼스](https://developers.kakao.com/)는 카카오 개발자 웹사이트이다.
- 카카오 API는 개발자 웹사이트에 등록된 각각의 애플리케이션 정보 기반으로 동작하므로, 카카오 API를 사용하려면 개발자 웹사이트에 앱을 등록해야 한다.
  >- 카카오 플랫폼
  > 카카오 플랫폼 구조와 지원하는 오픈 API 종류, 카카오계정, 연결 등 플랫폼 이용에 필요한 참고 지식은 [카카오 플랫폼 이해하기 가이드](https://developers.kakao.com/docs/latest/ko/getting-started/platform)에서 안내

- 앱 만들기 
![image](https://user-images.githubusercontent.com/65120581/133536658-9cb2b7f7-755f-4981-93fb-7afac0be148a.png)
- 앱 키를 이용해서 API 통신
![image](https://user-images.githubusercontent.com/65120581/133536832-a51000f1-9f70-4b44-922a-53c3716105e8.png)

## 키워드로 장소 검색

- 질의어에 매칭된 장소 검색 결과를 지정된 정렬 기준에 따라 제공
- 현재 위치 좌표, 반경 제한, 정렬 옵션, 페이징 등의 기능을 통해 원하는 결과를 요청 할 수 있음
- 앱 REST API 키를 헤더에 담아 GET으로 요청
- 원하는 검색어와 함게 결과 형식 파라미터의 값을 선택적으로 추가 할 수 있음
- 응답은 JSON과 XML 형식을 지원

> 참조 <br>
> [문서>로컬>개발가이드>](https://developers.kakao.com/docs/latest/ko/local/dev-guide)


## Request
- URL
```restapi
GET /v2/local/search/keyword.{format} HTTP/1.1
Host: dapi.kakao.com
Authorization: KakaoAK {REST_API_KEY}
```
