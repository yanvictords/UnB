#include "../../include/DetectorTool/record.h"
#include "../../include/DetectorTool/identifier.h"
#include "../../include/DetectorTool/ui.h"

long long record (struct in_addr sin_addr, long long operation, int protocol) {
	struct COUNT_ADDR * root, * listAux, *predecessor;
	unsigned long sAddr = sin_addr.s_addr;

	 // TODO : verificar apenas pelo ip, e não por protocolo
	root = getProtocolRoot(protocol);

	listAux = root;	
	predecessor = NULL;

	// If the IP address is already registered in the list, updates the counter
	// and sets the root list to the last updated counter node
	while (listAux != NULL) {
		// If the IP address was found
		if (listAux->sin_addr.s_addr == sAddr) {
			listAux->count += operation;
			
			// Checks whether the host should be dropped from the list (cases: black list or no more pending requests)
			if (mustKeepHostOnTheList(listAux)) {
				// If the node isn't the root node yet, then do it
				if (predecessor != NULL) {
					predecessor->next = listAux->next;
					listAux->next = root;
					root = listAux;
				}
				
				setProtocolRoot(protocol, root);
				return root->count;

			// Else: must to remove the node from the list
			} else {
				// if the node which will be dropped isn't the root
				if (predecessor != NULL) {
					predecessor->next = listAux->next;
				} else {
					setProtocolRoot(protocol, listAux->next);
				}

				// Returns the counter of removed node
				int newCounter = listAux->count;
				free(listAux);

				return newCounter;
			}
		}

		predecessor = listAux;
		listAux=listAux->next;
	}

	// If IP isn't registered yet, then updates the root to be the newer counter node
	root = create_node(root, sAddr);
	root->count += operation;

	mustKeepHostOnTheList(root);
	setProtocolRoot(protocol, root);
	
	return root->count;
}

bool mustKeepHostOnTheList (struct COUNT_ADDR * listAux) {
	// // Positive counter -> greather tha 100 packets, can be dropped from the list
	// if (listAux->count > _HIGH_LIMIT) {
	// 	printAnotherStatus(_MODULE_RECORD, _NORMAL_OP, "Positive counter. Greather than limit defined. Removing from the list.");
	// 	return false;
	// }

	// If there is a pendant request
	if (listAux->count > 0) {
		printAnotherStatus(_MODULE_RECORD, _NORMAL_OP, "Positive counter. Waiting for matching with the destiny IP address.");
		return true;
	}

	// If all requests were responded
	if (listAux->count == 0) {
		printAnotherStatus(_MODULE_RECORD, _NORMAL_OP, "Matching. All operations with this IP address were resolved.");
		return false;
	}

	// If the counter demonstrate a characteristic of DDoS attack by reflection
	if (listAux->count < (_LOW_LIMIT * (-1))) {
		printAnotherStatus(_MODULE_RECORD, _ANOMALOUS_OP, "[WARNING] Anomalous operation. The counter negative value is less than allowed.");
		return false;
	}

	// Stay alert
	if (listAux->count < 0) {
		printAnotherStatus(_MODULE_RECORD, _ANOMALOUS_OP, "[WARNING] Anomalous operation. A negative counter was detected.");
		return true;
	}
}

void setProtocolRoot (int protocol, struct COUNT_ADDR * root) {
	switch (protocol) {
		case _DNS:
			_pDns = root;
			break;
		case _NTP: // TODO
			_pNtp = root;
			break;
		case _SNMP: // TODO
			_pSnmp = root;
			break;
		case _SSDP: // TODO
			_pSsdp = root;
			break;
	}	
}

struct COUNT_ADDR * getProtocolRoot (int protocol) {	
	switch (protocol) {
		case _DNS:
			return _pDns;	
		case _NTP: // TODO
			return _pNtp;
		case _SNMP: // TODO
			return _pSnmp;
		case _SSDP: // TODO
			return _pSsdp;
	}
}

struct COUNT_ADDR * create_node (struct COUNT_ADDR * next, unsigned long addr) {
	struct COUNT_ADDR * newRoot = (struct COUNT_ADDR*) malloc(sizeof(struct COUNT_ADDR*));
	
	newRoot->next = next;
	newRoot->count = 0;
	newRoot->sin_addr.s_addr = addr;

	return newRoot;
}

void printAllCounters (int protocol) {
	char aux[4096];
	bool nullList = true;
	struct COUNT_ADDR * listAux;
	listAux = getProtocolRoot(protocol);

	if (listAux!=NULL) {
		printf("\n@Listing All Counters: \n");
		nullList = false;
	}

	while (listAux!=NULL) {
		inet_ntop(AF_INET, &(listAux->sin_addr), aux, 4096);
		printf("| IP: %s - Counter: %lld\n", aux, listAux->count); 
		listAux=listAux->next;
	}

	if (!nullList) {
		printf("\n");
	}
}

