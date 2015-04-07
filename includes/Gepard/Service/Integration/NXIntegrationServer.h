#pragma once
#include "../interprocess.h"
#include "../gpd_messaging.h"

#include "../../Topology_Geometry/GPDSolid.h"
#include "../../Surfaces/GPDSurfaces_inc.h"
#include "../../Curves/GPDCurve_inc.h"
#include "../../BasicMath/basicfuncs.h"

#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>

#include <list>
#include <streambuf>
#include <iostream>
#include <fstream>

namespace Gepard {

    class MathModel;

    namespace Service {
        namespace Integration {

enum INTER_STATES
{
    INTER_WAITING,
    INTER_STARTED,
    INTER_BYTES_CNT,
    INTER_CHECKSUM,
    INTER_DATA_TRANSFER,
    INTER_FINISHED,
    INTER_READY
};

struct membuf : std::streambuf
{
    membuf(char* begin, char* end) {
        this->setg(begin, begin, end);
    }
};


class NXIntegrationServer : public NamedPipeServer
{
private:
    unsigned int m_checksum;
    INTER_STATES m_curState;
    unsigned int m_bytesNumber;
    char* m_data;
    char* data_ptr;
    
    Gepard::MathModel *m_mathModelPtr;

    struct ptree
    {
        std::string data;                          // data associated with the node
        std::list< std::pair<std::string, ptree> > children; // ordered list of named children
    };

    /**
     *  Парсинг полученных данных
     */
    void ParseData();
    void ParseComponents(const boost::property_tree::ptree &pt);
    void ParseParts(const boost::property_tree::ptree &pt);
    void ParsePart(const boost::property_tree::ptree &pt);
    void ParseBodies(const boost::property_tree::ptree &pt);
    void ParseBody(const boost::property_tree::ptree &pt);
    void ParseFaces(const boost::property_tree::ptree &pt,
                    Gepard::Topology_Geometry::GPDSolid *solidPtr);
    void ParseFace(const boost::property_tree::ptree &pt,
                   Gepard::Topology_Geometry::GPDSolid *solidPtr);
    void ParseEdges(const boost::property_tree::ptree &pt);
    void ParseEdge(const boost::property_tree::ptree &pt);
    void ParseConstraints(const boost::property_tree::ptree &pt);
    void ParseConstraint(const boost::property_tree::ptree &pt);
    std::vector<long int> StrToInt(const std::string& str);
    std::vector<double> StrToDouble(const std::string& str);

public:
    
    NXIntegrationServer();
    virtual ~NXIntegrationServer(void);

    
     /**
      *  Создать сервер
      */
    bool CreateServerForNX(Gepard::MathModel *gepard_model);

    /**
     *  Функция передает ответ на запрос клиента
     */
    void GetAnswerToRequest( char* pchRequest,DWORD cbBytesRead, char* pchReply, LPDWORD pchBytes ) override;


};

        /**
         *  Глобальный инстанс класса
         */
        extern NXIntegrationServer GPDNamedPipeServer;

        }
    }

}